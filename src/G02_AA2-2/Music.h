#pragma once
#include <SDL_mixer.h>
#include <string.h>
#include <unordered_map>

class Music {
private:
	std::unordered_map < std::string, Mix_Music *> m_musicData;
	static Music *music;
	bool on;
public:
	static Music *Instance()
	{
		if (music == nullptr) { music = new Music; }
		return music;
	};
	Music();
	~Music();
	void LoadMusic(const std::string &,const std::string &);
	bool IsPlaying() const;
	void SetVolume(const int &) const;
	void PlayMusic(const std::string &, const int &);
	void PauseMusic() const;
	void ResumeMusic() const;
	bool IsPaused() const;
	void SetState(const bool &);
	bool GetState() const;
	void ResetMap();
};