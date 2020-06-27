#include <core/os/input.h>
#include <scene/3d/camera.h>
#include <scene/scene_string_names.h>
#include <scene/gui/color_rect.h>

#include "cross_fade_lod_editor_plugin.h"
#include "editor/editor_scale.h"

CrossFadeLodEditorPlugin::CrossFadeLodEditorPlugin(EditorNode *p_editor) {
	_editor = p_editor;

	_toolbar = memnew(HBoxContainer);
	add_control_to_container(CONTAINER_SPATIAL_EDITOR_MENU, _toolbar);
	_toolbar->hide();

	{
		Button *button = memnew(Button);
		button->set_text(TTR("Replace nodes"));
		button->connect("pressed", this, "replace_nodes");
		_toolbar->add_child(button);
	}
}

CrossFadeLodEditorPlugin::~CrossFadeLodEditorPlugin() {
}

void CrossFadeLodEditorPlugin::replace_nodes() {
	cross_fading_lod->replace_nodes();
}

bool CrossFadeLodEditorPlugin::forward_spatial_gui_input(Camera *p_camera, const Ref<InputEvent> &p_event) {

	if (cross_fading_lod == nullptr)
		return false;

	cross_fading_lod->m_manual_viewer_pos = p_camera->get_global_transform().origin;

	bool captured_event = false;

	return captured_event;
}

void CrossFadeLodEditorPlugin::edit(Object *p_object) {

	//printf("Edit %i\n", p_object);
	CrossFadeLod *node = p_object ? Object::cast_to<CrossFadeLod>(p_object) : nullptr;

	if (cross_fading_lod) {
		cross_fading_lod->disconnect(SceneStringNames::get_singleton()->tree_exited, this, "cross_fading_lod_exited_scene");
	}

	cross_fading_lod = node;

	if (cross_fading_lod) {
		cross_fading_lod->connect(SceneStringNames::get_singleton()->tree_exited, this, "cross_fading_lod_exited_scene");
	}
}

void CrossFadeLodEditorPlugin::cross_fading_lod_exited_scene() {
	//print_line("HeightMap exited scene");
	edit(NULL);
}

bool CrossFadeLodEditorPlugin::handles(Object *p_object) const {
	return p_object->is_class("CrossFadeLod");
}

void CrossFadeLodEditorPlugin::make_visible(bool p_visible) {
	_toolbar->set_visible(p_visible);
}

void CrossFadeLodEditorPlugin::_bind_methods() {

	ClassDB::bind_method(D_METHOD("cross_fading_lod_exited_scene"), &CrossFadeLodEditorPlugin::cross_fading_lod_exited_scene);
	ClassDB::bind_method(D_METHOD("replace_nodes"), &CrossFadeLodEditorPlugin::replace_nodes);
}
