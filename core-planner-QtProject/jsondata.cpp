#include "jsondata.h"

JsonData::JsonData()
{

}

void JsonData::inFromFile(const QString &fWay, MdiChild *Parent)
{
    try{
        QFile file;
        file.setFileName(fWay);
        if (!file.open(QIODevice::ReadOnly|QFile::Text))
        {
            throw QString("ERROR OPEN TO READ FILE: " + fWay);
        }
        doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
        file.close();
        if(docError.errorString().toInt()!=QJsonParseError::NoError)
        {
            throw QString("ERROR JSON PARSE");
        }
        QJsonValue sizeScene = QJsonValue(doc.object().value("Size scene"));
        int width = sizeScene.toObject().value("width").toInt();
        int height = sizeScene.toObject().value("height").toInt();
        Parent->SetSceneParametrs(width,height);

        QJsonArray docArr = QJsonValue(doc.object().value("figures")).toArray();
        InitializeSceneFromFile(Parent,docArr);

    }
    catch (QString error) {
        qDebug()<<error;
    }

}

void JsonData::outToFile(const QString &fWay, MdiChild *Parent)
{
    try {

        if(Parent == NULL)
        {
            throw QString("ERROR PARENT == NULL");
        }
        QFile file;
        file.setFileName(fWay);
        if(!file.open(QIODevice::WriteOnly))
        {
            throw QString("ERROR NOT OPEN FILE "+fWay);
        }
        QJsonObject mainStruct;
        QJsonObject sizeScene;
        sizeScene.insert("width", Parent->scene->sceneRect().toRect().width());
        sizeScene.insert("height", Parent->scene->sceneRect().toRect().height());
        mainStruct.insert("Size scene", sizeScene);
        QJsonArray recordsArray;

        Parent->DeleteGrid();
        QList<QGraphicsItem *> itm = Parent->scene->items();
        for(int i = 0; i < itm.size(); i++)
        {
            GraphicItem *item = qgraphicsitem_cast<GraphicItem*>(itm[i]);
            GraphicItemInfo Iformation = item->GetItemInfo();

            QJsonObject recordObject;
            recordObject.insert("Type", QJsonValue::fromVariant(Iformation.Type));
            recordObject.insert("Value", QJsonValue::fromVariant(Iformation.Value));
            recordObject.insert("Angle", QJsonValue::fromVariant(Iformation.Angle));

            QJsonObject position;
            position.insert("x",Iformation.X);
            position.insert("y",Iformation.Y);
            recordObject.insert("Position", position);
            QJsonObject size;
            size.insert("width",Iformation.Width);
            size.insert("height",Iformation.Height);
            recordObject.insert("Size", size);
            recordsArray.push_back(recordObject);
        }
        Parent->DrawGrid();

        mainStruct.insert("figures",recordsArray);
        QJsonDocument doc(mainStruct);
        file.write("\n" + doc.toJson()+"\n");
        file.close();
    }
    catch (QString error) {
        qDebug()<<error;
    }
}

void JsonData::outInitHistoryFile(const QString &fWay, MdiChild *Parent)
{
    if(Parent == NULL)
    {
        return;
    }

    QFile file;
    file.setFileName(fWay);
    if(file.open(QIODevice::WriteOnly))
    {
        QJsonObject mainStruct;
        QJsonArray scenesArray;
        for(int i = 0; i < 1; i++)
        {
            QJsonObject scene;
            QJsonArray recordsArray;

            Parent->DeleteGrid();
            QList<QGraphicsItem *> itm = Parent->scene->items();
            for(int i = 0; i < itm.size(); i++)
            {
                GraphicItem *item = qgraphicsitem_cast<GraphicItem*>(itm[i]);
                GraphicItemInfo Iformation = item->GetItemInfo();

                QJsonObject recordObject;
                recordObject.insert("Type", QJsonValue::fromVariant(Iformation.Type));
                recordObject.insert("Value", QJsonValue::fromVariant(Iformation.Value));
                recordObject.insert("Angle", QJsonValue::fromVariant(Iformation.Angle));

                QJsonObject position;
                position.insert("x",Iformation.X);
                position.insert("y",Iformation.Y);
                recordObject.insert("Position", position);
                QJsonObject size;
                size.insert("width",Iformation.Width);
                size.insert("height",Iformation.Height);
                recordObject.insert("Size", size);
                recordsArray.push_back(recordObject);
            }
            Parent->DrawGrid();
            scene.insert("figures", recordsArray);
            scenesArray.push_back(scene);
        }
        mainStruct.insert("Scenes", scenesArray);

        QJsonDocument doc(mainStruct);
        file.write("\n" + doc.toJson()+"\n");
        file.close();
    }
    else
    {
     qDebug()<<"ERROR";
    }
}

void JsonData::outHistoryToFile(const QString &fWay, MdiChild *Parent)
{
    QFile file;
    file.setFileName(fWay);
    if(file.open(QIODevice::ReadOnly|QFile::Text))
    {
        doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
    }
    file.close();
    if(docError.errorString().toInt()==QJsonParseError::NoError)
    {
        QJsonArray scenesArray = QJsonValue(doc.object().value("Scenes")).toArray();

        QJsonObject scene;
        QJsonArray recordsArray;
        Parent->DeleteGrid();
        QList<QGraphicsItem *> itm = Parent->scene->items();
        for(int i = 0; i < itm.size(); i++)
        {
            GraphicItem *item = qgraphicsitem_cast<GraphicItem*>(itm[i]);
            GraphicItemInfo Iformation = item->GetItemInfo();

            QJsonObject recordObject;
            recordObject.insert("Type", QJsonValue::fromVariant(Iformation.Type));
            recordObject.insert("Value", QJsonValue::fromVariant(Iformation.Value));
            recordObject.insert("Angle", QJsonValue::fromVariant(Iformation.Angle));

            QJsonObject position;
            position.insert("x",Iformation.X);
            position.insert("y",Iformation.Y);
            recordObject.insert("Position", position);
            QJsonObject size;
            size.insert("width",Iformation.Width);
            size.insert("height",Iformation.Height);
            recordObject.insert("Size", size);
            recordsArray.push_back(recordObject);
        }
        Parent->DrawGrid();
        scene.insert("figures", recordsArray);
        scenesArray.push_back(scene);

        QJsonObject mainStruct;
        mainStruct.insert("Scenes", scenesArray);

        QFile file;
        file.setFileName(fWay);
        if(file.open(QIODevice::WriteOnly))
        {
            QJsonDocument doc(mainStruct);
            file.write("\n" + doc.toJson()+"\n");
            file.close();
        }
        else
        {
            qDebug()<<"ERROR";
        }
    }
    else
    {
        qDebug()<<"ERROR";
    }
}

void JsonData::InitializeSceneFromFile(MdiChild *Parent, QJsonArray &docArr)
{
    for(int i = 0; i<docArr.count();i++)
    {
        GraphicItemInfo Information;
        Information.Type = docArr.at(i).toObject().value("Type").toString();
        Information.Value = docArr.at(i).toObject().value("Value").toString();
        QJsonValue posVal = QJsonValue(docArr.at(i).toObject().value("Position"));
        Information.X = posVal.toObject().value("x").toDouble();
        Information.Y = posVal.toObject().value("y").toDouble();
        QJsonValue sizeVal = QJsonValue(docArr.at(i).toObject().value("Size"));
        Information.Width = sizeVal.toObject().value("width").toDouble();
        Information.Height = sizeVal.toObject().value("height").toDouble();
        Information.Angle = docArr.at(i).toObject().value("Angle").toDouble();

        if(Information.Type == "Picture")
        {
            ItemByPicture *item = new ItemByPicture(Information.Width, Information.Height, Information.Value, Parent);
            item->setPos(Information.X, Information.Y);
            item->setRotation(Information.Angle);
            Parent->scene->addItem(item);
        }
        else
        {
            ItemByColor *item = new ItemByColor(Information.Width, Information.Height, QColor(Information.Value), Parent);
            item->setPos(Information.X, Information.Y);
            item->setRotation(Information.Angle);
            Parent->scene->addItem(item);
        }
    }
}

void JsonData::InitScenFromFile(const QString &fWay, MdiChild *Parent, int Version)
{
    QFile file;
    file.setFileName(fWay);
    if(file.open(QIODevice::ReadOnly|QFile::Text))
    {
        doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
    }
    file.close();
    if(docError.errorString().toInt()==QJsonParseError::NoError)
    {
        QJsonArray sceneArr = QJsonValue(doc.object().value("Scenes")).toArray();
        QJsonArray docArr = QJsonValue( sceneArr.at(Version).toObject().value("figures")).toArray();
        Parent->LastActive = NULL;
        Parent->DeleteGrid();
        Parent->scene->clear();
        Parent->DrawGrid();
        InitializeSceneFromFile(Parent,docArr);
    }
}

void JsonData::DeleteHighVersions(const QString &fWay, int Version)
{
    QFile file;
    file.setFileName(fWay);
    if(file.open(QIODevice::ReadWrite|QFile::Text))
    {
        doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
    }
    file.close();
    if(docError.errorString().toInt()==QJsonParseError::NoError)
    {
        QJsonArray sceneArr = QJsonValue(doc.object().value("Scenes")).toArray();
        for(int j = 0; j<sceneArr.count();j++)
        {
            while(Version+1 < sceneArr.size()){
                sceneArr.removeLast();
            }
        }
        QJsonObject mainStruct;
        mainStruct.insert("Scenes",sceneArr);

        if(file.open(QIODevice::ReadWrite|QFile::Text))
        {
            QJsonDocument doc(mainStruct);
            file.resize(0);
            file.write("\n" + doc.toJson()+"\n");
        }
        file.close();
    }
}
