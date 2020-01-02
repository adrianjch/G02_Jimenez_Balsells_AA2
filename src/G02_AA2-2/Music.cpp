#include "Music.h"

Music::Music() {
	const Uint8 mixFlags{ MIX_INIT_MP3 };
	if (!Mix_Init(mixFlags))
		throw "No es pot inicialitzar SDL_mixer";
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

bool Music::IsPlaying() const {
	return Mix_PlayingMusic();
}

void Music::SetVolume(const int &volume) const{
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

void Music::ResetMap() {
	for (auto &t : m_musicData) Mix_FreeMusic(t.second), t.second = nullptr;
	m_musicData.clear();
}

Music* Music::music = nullptr;