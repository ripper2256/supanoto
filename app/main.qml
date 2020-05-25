import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Supanoto")
    Column{

        ScrollView {
            id: view
            anchors.fill: parent

            TextArea {
                id: mainNote
                placeholderText: qsTr("Enter your Note")
            }

        }
        Button {
            id: saveButton
            text: qsTr("Save")
        }
    }

}
