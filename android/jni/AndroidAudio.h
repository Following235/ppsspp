#pragma once

#include <string>

typedef int (*AndroidAudioCallback)(short *buffer, int num_samples);

class AudioContext {
public:
	AudioContext(AndroidAudioCallback cb, int _FramesPerBuffer, int _SampleRate);
	virtual bool Init() { return false; }
	virtual int AudioRecord_Start(int sampleRate) { return false; };
	virtual int AudioRecord_Stop() { return false; };
	virtual ~AudioContext() {}

protected:
	AndroidAudioCallback audioCallback;

	int framesPerBuffer;
	int sampleRate;
};

struct AndroidAudioState;

// It's okay for optimalFramesPerBuffer and optimalSampleRate to be 0. Defaults will be used.
AndroidAudioState *AndroidAudio_Init(AndroidAudioCallback cb, int optimalFramesPerBuffer, int optimalSampleRate);
bool AndroidAudio_Recording_SetSampleRate(AndroidAudioState *state, int sampleRate);
bool AndroidAudio_Recording_Start(AndroidAudioState *state);
bool AndroidAudio_Recording_Stop(AndroidAudioState *state);
bool AndroidAudio_Recording_State(AndroidAudioState *state);
bool AndroidAudio_Pause(AndroidAudioState *state);
bool AndroidAudio_Resume(AndroidAudioState *state);
bool AndroidAudio_Shutdown(AndroidAudioState *state);
