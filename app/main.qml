import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.13
import database 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Supanoto")


    Database {
        id:db
    }

    /*ListModel {
        id: model
          ListElement {
              name: "Eine sehr lange notiz"

          }
          ListElement {
              name: "Eine lange notiz"

          }
          ListElement {
              name: "foobar"

          }
      }*/

    RowLayout{
        spacing: 10
        anchors.fill: parent

        ListView {
            id: listView
            Layout.fillHeight: true
            Layout.preferredWidth: 180
            Layout.fillWidth: false
            model: db.dbSQLselect("*")
            delegate: Component {
                Item {
                    width: 180; height: 40
                    Column {
                        Text { text: name }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            listView.currentIndex = index;
                            console.log(model.get(index).name);
                            mainNote.text = model.get(index).name;

                        }
                    }
                }

            }
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            highlightFollowsCurrentItem: true
            focus: true
        }

        ColumnLayout {
            id: column
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 2

            ScrollView {
                id: scrollView
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true

                TextArea {
                    id: mainNote
                    clip: true
                    wrapMode: Text.WordWrap

                    placeholderText: qsTr("Enter your Note")
                }

            }
            Row{
                spacing: 15
                Button {
                    id: saveButton
                    text: qsTr("Save")
                    onClicked: db.dbSQLinsert(mainNote.text)
                }
                Button {
                    id: newButton
                    text: qsTr("New Note")
                }
            }
        }
    }
}
