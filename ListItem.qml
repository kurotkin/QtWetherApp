import QtQuick 2.12

Rectangle {
    id: root
    radius: 10

    border.width: 2
    border.color: "gray"

    property alias text: butonText.text


    Text {
        id: butonText
        text: "Width: " + root.width + "\nHeight: " + root.height
        font.bold: true
        font.italic: true
        font.pointSize: 13//"Button"
        anchors.centerIn: parent
    }

}

