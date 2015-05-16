import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Item {
    id: rootWindow

    RowLayout {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: Layout.minimumHeight

        Rectangle {
            anchors.fill: parent
            color: "black"
            opacity: 0.65
        }

        Button {
            text: "Hey"
        }
    }
}
