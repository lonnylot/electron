// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_API_ATOM_API_NATIVE_IMAGE_H_
#define ATOM_COMMON_API_ATOM_API_NATIVE_IMAGE_H_

#include "native_mate/handle.h"
#include "native_mate/wrappable.h"
#include "ui/gfx/image/image.h"

namespace gfx {
class Size;
}

namespace atom {

namespace api {

class NativeImage : public mate::Wrappable {
 public:
  static mate::Handle<NativeImage> Create(v8::Isolate* isolate,
                                          const gfx::Image& image);

 protected:
  NativeImage(const gfx::Image& image);
  virtual ~NativeImage();

  // mate::Wrappable:
  mate::ObjectTemplateBuilder GetObjectTemplateBuilder(
      v8::Isolate* isolate) override;

 private:
  v8::Handle<v8::Value> ToPNG(v8::Isolate* isolate);
  bool IsEmpty();
  gfx::Size GetSize();

  gfx::Image image_;

  DISALLOW_COPY_AND_ASSIGN(NativeImage);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_COMMON_API_ATOM_API_NATIVE_IMAGE_H_
