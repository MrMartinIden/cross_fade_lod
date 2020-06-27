#include "register_types.h"

#include "cross_fade_lod_editor_plugin.h"
#include "entity_node.h"

void register_cross_fade_lod_types() {
#ifndef _3D_DISABLED
	ClassDB::register_class<CrossFadeLod>();
	ClassDB::register_class<EntityNode>();

#ifdef TOOLS_ENABLED
	EditorPlugins::add_by_type<CrossFadeLodEditorPlugin>();
#endif
#endif
}

void unregister_cross_fade_lod_types() {
}
