#include "Music.h"

Music::Music() {
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		throw "Unable to initialize SDL_mixer audio systems";

	on = true;
}

Music::~Music() {
	Mix_CloseAudio();
	Mix_Quit();
}

void Music::LoadMusic(const std::string &id, const std::string &path) {
	Mix_Music *soundtrack{ Mix_LoadMUS(path.c_str()) };
	if (!soundtrack) throw "Unable to load the Mix_Music soundtrack";
	m_musicData[id] = soundtrack;
}

void Music::CloseMusic() const{
	Mix_CloseAudio();
}

bool Music::IsPlaying() const {
	return Mix_PlayingMusic();
}

void Music::SetVolume(const int &volume) {
	if (volume > MIX_MAX_VOLUME)
		Mix_VolumeMusic(MIX_MAX_VOLUME);
	else
		Mix_VolumeMusic(volume);
}

void Music::PlayMusic(const std::string &id, const int &iterations) {
	Mix_PlayMusic(m_musicData[id], iterations);
}

void Music::PauseMusic() const {
	Mix_PauseMusic();
}

void Music::ResumeMusic() const {
	Mix_ResumeMusic();
}

bool Music::IsPaused() const {
	return Mix_PausedMusic();
}

void Music::SetState(const bool &state) {
	on = state;
	if (on) {
		SetVolume(MIX_MAX_VOLUME);
	}
	else {
		SetVolume(0);
	}
}

bool Music::GetState() const {
	return on;
}

Music* Music::music = nullptr;