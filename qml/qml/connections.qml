import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml 2.2

Window 
{
    id:win;
    width: 400;
    height: 300;
    visible: true;
    Button
    {
        id:btn;
        x:0;
        y:0;
        text:"按钮";
    }
    
    function quit_qt()
    {
        Qt.quit();
    }
    
    // Conponent.onComleted 方法进行信号和槽的连接
    Component.onCompleted: 
    {
        btn.onClicked.connect(quit_qt);
    }
    
    // 这个 是通过连接对象 Connections 进行连接的
    //    Connections
    //    {
    //        target: btn;
    //        onClicked: quit_qt();
    //    }
    
}
