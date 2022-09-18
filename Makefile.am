#

SUBDIRS		= doc
SUBDIRS		+= man
SUBDIRS		+= src
SUBDIRS		+= xsd

dist_doc_DATA	= README

@DX_RULES@
dist_pdf_DATA	= $(DX_DOCDIR)/$(DX_PROJECT).pdf
$(dist_pdf_DATA): doxygen-doc
MOSTLYCLEANFILES	= $(DX_CLEANFILES)
