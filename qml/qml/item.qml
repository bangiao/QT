import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml 2.2

Window 
{
    width: 400;
    height: 300;
    visible: true;
    
    Text
    {
        text: "zhazha";
        color: "red";
        font.pointSize: 12;
        rotation: 30;
    }
//    LayoutItem
//    {
        
//    }

    Button
    {
        y: 40;
        text: "button";
        onClicked: 
        {
            console.log("@_@");
        }
    }
    
    Rectangle
   {
       x:30;
       y:80;
       width: 200;
       height: 30;
       color: "lightgray";
       border.width: 2;
       border.color: "blue";
       radius: 8;
//       Text
//       {
//           anchors.centerIn: parent;
//           text: "我是矩形";
//           color: "yellow";
//           font.pointSize: 12;
//       }
       TextInput
       {
           anchors.centerIn: parent;
           id:input;
           focus:true;
           width: 200;
           height: 30;
       }
   }
    
    Image
    {
        x:185;
        y:185;
        width: 100;
        height: 100;
        source: "http://pic55.nipic.com/file/20141208/19462408_171130083000_2.jpg";
        fillMode: Image.Stretch;
        
    }
}
