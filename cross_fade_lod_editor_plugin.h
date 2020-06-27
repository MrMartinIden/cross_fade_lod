#pragma once

#include "editor/editor_plugin.h"

#include "editor/editor_node.h"

#include "editor/editor_resource_preview.h"

#include "cross_fade_lod.h"

class CrossFadeLodEditorPlugin : public EditorPlugin {
	GDCLASS(CrossFadeLodEditorPlugin, EditorPlugin)
public:
	CrossFadeLodEditorPlugin(EditorNode *p_editor);
	~CrossFadeLodEditorPlugin();

	virtual bool forward_spatial_gui_input(Camera *p_camera, const Ref<InputEvent> &p_event);
	virtual String get_name() const { return "CrossFadeLoad"; }
	bool has_main_screen() const { return false; }
	virtual void edit(Object *p_object);
	virtual bool handles(Object *p_object) const;
	virtual void make_visible(bool p_visible);

	void replace_nodes();

	void remove_entities();

protected:
	static void _bind_methods();

private:
	void cross_fading_lod_exited_scene();

private:
	EditorNode *_editor;
	CrossFadeLod *cross_fading_lod;
	HBoxContainer *_toolbar;
};
