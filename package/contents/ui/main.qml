import QtQuick 2.6
import org.kde.kirigamiaddons.treeview 1.0 as KiriAdd
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0 as QQC

import com.github.tilorenz.dtplugin 1.0 as DTPlugin

RowLayout{
	property url dirPath: "file:///home/tino/projects/plasmoids/notes/testDir/"

	width: 600
	height: 500

	DTPlugin.DirTreeModel{
		id: dtMod
		url: dirPath
	}

	KiriAdd.TreeListView{
		id: tlv
		Layout.fillWidth: true
		Layout.fillHeight: true
		model: dtMod

		delegate: KiriAdd.BasicTreeItem{
			id: tlvDelegate
			label: fileName

			onClicked: if(isDir){
				dirPath = fileUrl
			} else{
				print("path: " + fileUrl)
			}
		}
	}

	QQC.Button{
		text: "Dir up"
		onClicked: {
			//print("dirup clicked")
			dtMod.dirUp()
		}
	}
}

