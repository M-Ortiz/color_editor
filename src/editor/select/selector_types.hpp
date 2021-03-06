#pragma once

#include "selector.hpp"
#include "../mouse_mode.hpp"
#include "../color/color_label.hpp"

#include <QCheckBox>
#include <QButtonGroup>
#include <QSpinBox>
#include <QComboBox>

namespace editor {
namespace select {
namespace selector_types {

class select_all : public selector {
public:
	select_all();
	
private:
	QCheckBox *select_nothing;
	
	QRegion select();
	
}; // select_all


class draw : public selector {
	Q_OBJECT
	
public:
	draw();
	
public slots:
	virtual void point_selected(const QPoint &point) override;
	
private:
	mouse_mode *exclude_mm;
	mouse_mode *select_mm;
	QButtonGroup *group;
	QSpinBox *side_length;
	QComboBox *region_type;
	
	QRect create_rect(const QPoint &point);
	
}; // draw


class color_match : public selector {
	Q_OBJECT
	
public:
	color_match();
	
public slots:
	virtual void point_selected(const QPoint &point) override;
	
private:
	color::color_label *source_color;
	mouse_mode *choose_color;
	QSpinBox *fuzziness;
	
	QRegion matching_pixels();
	bool within_fuzzy(const QColor &color);
	
}; // color_match

} // selector_types
} // select
} // editor
