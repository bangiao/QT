import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml 2.2

Window {
    width: 400;
    height: 300;
    visible: true;
    
    Text
    {
        id:txt;
        // anchors.centerIn: parent;
        font
        {
            bold:true;
            pointSize:20;
        }
        text: "hello world";
        Keys.onLeftPressed: x -= 10;
        Keys.onRightPressed: x += 10;
        
        Keys.onUpPressed: y -= 10;
        Keys.onDownPressed: y += 10;
        focus: true;
    }
    
    MouseArea
    {
        anchors.fill: parent;
        acceptedButtons: Qt.LeftButton | Qt.RightButton;
        onClicked: 
        {
            if (mouse.button == Qt.LeftButton)
            {
                txt.text = "LeftButton";
            }
            else
            {
                txt.text = "RightButton";
            }
        }
        onDoubleClicked: 
        {
            if (mouse.button == Qt.LeftButton)
            {
                txt.text = "LeftDoubleButton";
            }
            else
            {
                txt.text = "RightDoubleButton";
            }
        }
    }
}
