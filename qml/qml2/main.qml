import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    
    MouseArea
    {
        anchors.fill: parent;
        onClicked: 
        {
            Qt.quit();
        }
    }
    
    function test()
    {
        console.log("zhazha test");
    }
    
    Text
    {
        text: qsTr("Helloworld");
        anchors.centerIn: parent;
    }
    
    Component.onCompleted: 
    {
        test();
    }
}
