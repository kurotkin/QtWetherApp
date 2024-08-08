import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        anchors.fill: parent
        model: _model
        delegate: ListItem {
            width: parent.width
            text: _model.hourlyWeater[index].timeLine
        }
    }

}
