import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Supanoto")
    ColumnLayout {
        id: column
        anchors.fill: parent
        spacing: 2

        ScrollView {
            id: scrollView
            anchors.left: column.left
            anchors.right: column.right
            Layout.fillHeight: true
            clip: true

            TextArea {
                id: mainNote
                clip: true
                wrapMode: Text.WordWrap
                anchors.fill: scrollView
                placeholderText: qsTr("Enter your Note")


            }

        }

        Button {
            id: saveButton
            text: qsTr("Save")
        }
    }

}
