# UnityAbletonLink

UnityAbletonLink is an [Ableton Link](https://github.com/Ableton/link) plugin for [Unity](https://unity3d.com).

## Building plugins

After checked out the UnityAbletonLink repository, then check out all dependencies.

```
cd UnityAbletonLink
git submodule update --init --recursive
```

### For Mac
Open `UnityAbletonLink.xcodeproj` with Xcode, then build it.

### For Windows
Open `UnityAbletonLink.sln` with Visual Studio (ver. >= 2017), then build it.

### For Android
* Windows:  Run the `build_android_plugin.bat`.
* Mac or Linux: Run the `build_android_plugin.sh`.
`.so` will be generated in the `libs` folder.

## Setting the Unity project and the plugin.

Create a new Unity project.
Create the `Plugins` folder under the `Assets` folder in the project.

#### For Mac

Copy the `UnityAbletonLink.bundle` and the `CSharp/AbletonLink.cs` into the `Plugins` folder.

### For Windows

Copy the `CSharp/AbletonLink.cs` into the `Plugins` folder.
Create the `x86_64` folder under the `Plugins` folder.
Copy the `UnityAbletonLink.dll` into the `Plugins/x86_64` folder.

### For Android
Copy the `CSharp/AbletonLink.cs` into the `Plugins` folder.
Create the `Android` folder under the `Plugins` folder.
Copy the `libs` folder into the `Plugins/Android` folder.

### Common
`AbletonLink.cs` is a wrapper script for `UnityAbletonLink` plugin.
`AbletonLink` class is the singleton. So you can access it by using `AbletonLink.Instance()`.

## Write some code in Unity
Write some script to use it.
For example,

```Example.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Example : MonoBehaviour {

	private AbletonLink link;

	// Use this for initialization
	void Start () {
	}

	// Update is called once per frame
	void Update () {
        	double beat, phase, tempo, time;
		int numPeers;
        	AbletonLink.Instance.update(out beat, out phase, out tempo, out time, out numPeers);

		// We can obtain the latest beat and phase like this.
		Debug.Log ("beat: " + beat + " phase:" + phase);
	}
}
```

Attach the script to a GameObject (e.g. Main Camera or something).

## Play in Unity
Play the scene and play the other Ableton Link supported application such as Ableton Live, then you can see log messages like the following.
```
...
beat: 43.151854 phase:3.151854
UnityEngine.Debug:Log(Object)
beat: 43.265132 phase:3.265132
UnityEngine.Debug:Log(Object)
...
```

## License

These codes are licensed under CC0.

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed)
