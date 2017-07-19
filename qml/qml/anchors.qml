import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window
{
    visible: true;
    width: 480;
    height: 320;
    
    Rectangle
    {
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.leftMargin: 8;
        anchors.rightMargin: 6;
        width: 60;
        height: 40;
        color: "#0000ff";
    }
    
    Rectangle
    {
        id: centerRect;
        anchors.centerIn: parent;
        width: 80;
        height: 80;
        color: "red";
    }
    
    Rectangle
    {
        anchors.top: centerRect.bottom;
        anchors.margins: 4;
        anchors.horizontalCenter: centerRect.horizontalCenter;
        anchors.horizontalCenterOffset: 20;
        width: 60;
        height: 30;
        color: "green";
        border.width: 1;
        border.color: "#004400";
    }
    
    Rectangle
    {
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 12;
        width: 200;
        height: 40;
        color: "gray";
    }
}
