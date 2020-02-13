
VERSION_MAJOR := 0
VERSION_MINOR := 1
VERSION_PATCH := 0

VERSION := $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

CFLAGS += -DVERSION_MAJOR=$(VERSION_MAJOR)
CFLAGS += -DVERSION_MINOR=$(VERSION_MINOR)
CFLAGS += -DVERSION_PATCH=$(VERSION_PATCH)
CFLAGS += -DVERSION=$(VERSION)

PREFIX ?= /usr
