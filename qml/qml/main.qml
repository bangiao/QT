import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    title: "zhazha"
    width: 480;
    height: 320;
    
    Text {
        id:texthello;
        anchors.centerIn: parent;
        text: "Hello world";
        font {
            bold: true;
            pointSize: 50;
            italic: true;
        }
        
        MouseArea {
            anchors.fill: parent;
            onClicked: {
                texthello.text = "Hello";
            }
        }
    }
}
