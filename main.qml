import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        anchors.fill: parent

        contentWidth: 320
        flickableDirection: Flickable.AutoFlickDirection

        model: ListModel {
            id: listModel
        }
        delegate: Row {
            Text { text: '<b>Name:</b> ' + name; width: 160 }
            Text { text: '<b>Number:</b> ' + number; width: 160 }
        }
    }

}
