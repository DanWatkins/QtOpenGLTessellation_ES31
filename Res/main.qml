import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Item {
    id: rootWindow
    width: 800
    height: 600

    Item {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 40

        Rectangle {
            anchors.fill: parent
            color: "black"
            opacity: 0.65
        }

        RowLayout {
            id: menuButtons
            anchors.fill: parent
            anchors.margins: 5
            spacing: 10

            width: Layout.minimumWidth
            height: Layout.minimumHeight

            Button {
                id: button_captureCursor
                text: "Do something"
            }
        }
    }
}
