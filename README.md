# UnityAbletonLink

UnityAbletonLink is an [Ableton Link](https://github.com/Ableton/link) plugin for [Unity](https://unity.com).

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

### For Linux

Run the following on a terminal.
```
mkdir build
cd build
cmake ..
make
```
Then `libUnityAbletonLink.so` is generated in `build` directory.

## Unity project settings

Create a new Unity project.
Create `Plugins` folder under `Assets` folder in the project.

### For Mac

Copy `UnityAbletonLink.bundle` and `CSharp/AbletonLink.cs` into `Plugins` folder.

### For Windows

Copy `CSharp/AbletonLink.cs` into `Plugins` folder.
Create `x86_64` folder under `Plugins` folder.
Copy `UnityAbletonLink.dll` into `Plugins/x86_64` folder.

### For Android

Copy `CSharp/AbletonLink.cs` into `Plugins` folder.
Create `Android` folder under `Plugins` folder.
Copy `libs` folder into `Plugins/Android` folder.

### For Linux
Copy `UnityAbletonLink.so` and `CSharp/AbletonLink.cs` into `Plugins` folder.

### Common
`AbletonLink.cs` is a wrapper script for `UnityAbletonLink` plugin.
`AbletonLink` class is the singleton. So you can access it by using `AbletonLink.Instance`.

## Write some code in Unity

Write some script to use this plugin.
For example,

```Example.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Example : MonoBehaviour
{
	private AbletonLink link;

	void Update ()
	{
		double beat, phase, tempo, time;
		int numPeers;
		
		// We can get the latest beat, phase and tempo as follows.
        AbletonLink.Instance.update(out beat, out phase, out tempo, out time, out numPeers);

		Debug.Log ("beat: " + beat + " phase:" + phase + " tempo:" + tempo);
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
