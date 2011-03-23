#include "XmlImageNode.h"

XmlImageNode::XmlImageNode(const char * tag) :
	XmlNode(tag) {
	XOJ_INIT_TYPE(XmlImageNode);

	this->img = NULL;
	this->out = NULL;
	this->pos = 0;
}

XmlImageNode::~XmlImageNode() {
	XOJ_CHECK_TYPE(XmlImageNode);

	if (this->img) {
		cairo_surface_destroy(this->img);
	}

	XOJ_RELEASE_TYPE(XmlImageNode);
}

void XmlImageNode::setImage(cairo_surface_t * img) {
	XOJ_CHECK_TYPE(XmlImageNode);

	if (this->img) {
		cairo_surface_destroy(this->img);
	}
	this->img = cairo_surface_reference(img);
}

cairo_status_t XmlImageNode::pngWriteFunction(XmlImageNode * image, unsigned char *data, unsigned int length) {
	for (unsigned int i = 0; i < length; i++, image->pos++) {
		if (image->pos == 30) {
			gchar * base64_str = g_base64_encode(image->buffer, image->pos);
			image->out->write(base64_str);
			g_free(base64_str);
			image->pos = 0;
		}
		image->buffer[image->pos] = data[i];
	}

	return CAIRO_STATUS_SUCCESS;
}

void XmlImageNode::writeOut(OutputStream * out) {
	XOJ_CHECK_TYPE(XmlImageNode);

	out->write("<");
	out->write(tag);
	writeAttributes(out);

	out->write(">");

	if (this->img == NULL) {
		g_error("XmlImageNode::writeOut(); this->img == NULL");
	} else {
		this->out = out;
		this->pos = 0;
		cairo_surface_write_to_png_stream(this->img, (cairo_write_func_t) &pngWriteFunction, this);
		gchar * base64_str = g_base64_encode(this->buffer, this->pos);
		out->write(base64_str);
		g_free(base64_str);

		this->out = NULL;
	}

	out->write("</");
	out->write(tag);
	out->write(">\n");
}
