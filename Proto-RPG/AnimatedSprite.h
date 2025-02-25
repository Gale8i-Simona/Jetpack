// ----------------------------------------------------------------
// From "Algorithms and Game Programming" in C++ by Alessandro Bria
// Copyright (C) 2024 Alessandro Bria (a.bria@unicas.it). 
// All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Sprite.h"
#include <vector>

namespace agp
{
	class AnimatedSprite;
}

// AnimatedSprite
// - implements animations
class agp::AnimatedSprite : public Sprite
{
	protected:

		std::vector<RectI> _frames;
		float _frameIterator;
		float _FPS;

	public:

		AnimatedSprite(
			SDL_Texture* spritesheet,
			const std::vector<RectI>& frames,
			float FPS,
			Direction keepARdir = Direction::NONE,
			const std::vector <int> resampling = std::vector<int>());

		float FPS() const { return _FPS; }
		void setFPS(float fps) { _FPS = fps; }
		float duration() { return _frames.size() / _FPS; }
		float currentTime() { return _frameIterator / _frames.size(); }

		// extends update method (+animations)
		virtual void update(float dt) override;

		// extends reset method (+ restart frameIterator )
		virtual void reset() override;
};