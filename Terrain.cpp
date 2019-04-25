#include "Terrain.h"

namespace Terrain
{
	RawEntity createTerrain(unsigned int edgeLength, unsigned int divisionFactor)
	{
		float texture1f = divisionFactor * 1.0f;
		float texture0f = 0.0f;
		std::vector<float> vertices = { -float(edgeLength), 0.0f, float(edgeLength), texture0f, texture0f,
										float(edgeLength), 0.0f, -float(edgeLength), texture1f, texture1f,
										-float(edgeLength), 0.0f, -float(edgeLength), texture0f, texture1f,
										float(edgeLength), 0.0f, float(edgeLength), texture1f, texture0f };

		std::vector<unsigned int> indices = { 0, 1, 2, 0, 3, 1 };

		return RawEntity(std::move(vertices), std::move(indices));
	}
}