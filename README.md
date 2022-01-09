# Simple Reverb

This is a simple reverb plugin made with the JUCE DSP module.

![SimpleReverb](/Resources/SimpleReverb.png)

## Manual

- drag sensitivity * 0.1: shift + drag
- undo/redo: cmd + z/cmd + shift + z
- edit mode: numeric keypress

## Building

```
$ git clone https://github.com/szkkng/SimpleReverb.git --recursive
$ cd SimpleReverb
$ cmake -S . -B build
$ cmake --build build
```

```
# Here's Plugin.
$ ls -l build/SimpleReverb_artefacts/VST3
```

## Other

- Tutorial: [How to Make a Simple Reverb with the JUCE DSP Module](https://suzuki-kengo.dev/posts/simple-reverb/)
- YouTube: [Simple Reverb - JUCE DSP module -](http://www.youtube.com/watch?v=jjTF3EwplWA)
