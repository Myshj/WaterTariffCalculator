import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Калькулятор оплаты за горячую воду")


    menuBar: MenuBar {
            Menu {
                title: qsTr("Файл")
                MenuItem {
                    text: qsTr("Новый")
                }
                MenuItem {
                    text: qsTr("Открыть")
                    shortcut: "Ctrl+O"
                }
                MenuItem {
                    text: qsTr("Сохранить")
                    shortcut: "Ctrl+S"
                }
                MenuItem {
                    text: qsTr("Выйти")
                    onTriggered: Qt.quit()
                }
            }

            Menu {
                title: qsTr("Статистика")
                MenuItem {
                    text: qsTr("Отобразить")
                }
            }
        }


    AlternativeMainWindow{
        anchors.fill: parent
    }
}
