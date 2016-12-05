#pragma once

#include <string>

#include "GLTFObject.h"
#include "GLTFTechnique.h"
#include "GLTFTexture.h"

namespace GLTF {
	class Material : public GLTF::Object {
	public:
		enum Type {
			MATERIAL,
			MATERIAL_COMMON,
			UNKNOWN
		};

		class Values {
		public:
			float ambient[4] = { 0.0, 0.0, 0.0, 1.0 };
			float diffuse[4] = { 0.0, 0.0, 0.0, 1.0 };
			GLTF::Texture* diffuseTexture = NULL;
			float emission[4] = { 0.0, 0.0, 0.0, 1.0 };
			float shininess[1] = { 0.0 };
			float specular[4] = { 0.0, 0.0, 0.0, 1.0 };

			void writeJSON(void* writer);
		};

		GLTF::Technique* technique = NULL;
		Type type = Type::UNKNOWN;
		Values* values = NULL;

		virtual void writeJSON(void* writer);
	};


	class MaterialCommon : public GLTF::Material {
	public:
		enum Technique {
			BLINN,
			PHONG,
			LAMBERT,
			CONSTANT
		};

		bool doubleSided = false;
		int jointCount = 0;
		bool transparent = false;

		Technique technique;

		const char* getTechniqueName();
		virtual void writeJSON(void* writer);
	};
}
