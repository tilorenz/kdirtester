import QtQuick 2.6
import QtQuick.Controls 2.0 as QQC

import com.github.tilorenz.kdirtestplugin 1.0 as KDTPlugin

QQC.Button{
	text: activate
	onClicked:{
		print("Button clicked.")
		plug.activate()
	}

	KDTPlugin.KDirTest{
		id: plug
	}
}
