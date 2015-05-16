import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import ES31_Test 1.0

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

    OpenGLRenderer {
        id: mainRenderable
        objectName: "mainRenderable"

        anchors.left: parent.left
        anchors.top: topBar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
