import QtQuick

Window {
    id: self

    width: 640
    height: 640
    visible: true
    title: qsTr("Radar")

    Radar {
        id: radar
        radio: 300
        type: Radar.Half
        anchors.centerIn: parent
    }
}
