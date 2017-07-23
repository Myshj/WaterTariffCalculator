import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    id: item1

    GroupBox {
        id: groupBox
        x: 20
        y: 22
        width: 410
        height: 176
        title: qsTr("Показания счетчика")
        antialiasing: false

        GridLayout {
            id: gridLayout
            anchors.fill: parent
            rows: 5
            columns: 4

            Text {
                id: cellLabel
                text: qsTr("Ячейка")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            Text {
                id: oldDataLabel
                text: qsTr("Было")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            Text {
                id: newDataLabel
                text: qsTr("Стало")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            Text {
                id: consumedLabel
                text: qsTr("Разница")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            Text {
                id: lessThen40Label
                text: qsTr("< 40 C")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            OldSpinBox {
                id: oldLessThen40SpinBox
                maximumValue: 9999
                decimals: 4
            }

            OldSpinBox {
                id: newLessThen40SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: consumedLessThen40SpinBox
                decimals: 4
                maximumValue: 9999
            }

            Text {
                id: from40To44Label
                text: qsTr("40 - 44 C")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            OldSpinBox {
                id: oldFrom40To44SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: newFrom40To44SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: consumedFrom40To44SpinBox
                decimals: 4
                maximumValue: 9999
            }

            Text {
                id: from45To49Label
                text: qsTr("45 - 49 C")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 16
            }

            OldSpinBox {
                id: oldFrom45To49SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: newFrom45To49SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: consumedFrom45To49SpinBox
                decimals: 4
                maximumValue: 9999
            }

            Text {
                id: greaterThen50Label
                text: qsTr("> 50 C")
                font.pixelSize: 16
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            OldSpinBox {
                id: oldGreaterThen50SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: newGreaterThen50SpinBox
                decimals: 4
                maximumValue: 9999
            }

            OldSpinBox {
                id: consumedGreaterThen50SpinBox
                decimals: 4
                maximumValue: 9999
            }
        }
    }
}
