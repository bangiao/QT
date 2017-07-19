import QtQuick 2.7
import QtQuick.Window 2.2

Window 
{
    id: win;
    visible: true;
    width: 400;
    height: 300;
    color: "black"
    Text
    {
        id:text;
        // anchors.centerIn: parent;
        color: "blue";
        text:"Center Text";
        font.pointSize: 50;
    }
    
    // 这种都是属性变化的 signal s
    
    onWidthChanged: width_change();

    onHeightChanged: 
    {
        text.y = (win.height - text.height) / 2;
    }
    
    function width_change()
    {
        text.x = (win.width - text.width) / 2;
    }
}
