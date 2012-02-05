// -----------------------------------------------------------------------------
//
// NsProp4iWidget.cc
//
// Naiad Studio property <vec4i>, source file.
//
// Copyright (c) 2011 Exotic Matter AB. All rights reserved.
//
// This file is part of Open Naiad Studio.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// * Neither the name of Exotic Matter AB nor its contributors may be used to
// endorse or promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// -----------------------------------------------------------------------------

#include "NsProp4iWidget.h"
#include "NsPropWidgetArgs.h"
#include "NsPropWidgetFactory.h"
#include "NsValueWidgetLayout.h"
#include "NsValueLineEdit.h"
#include <QAction>

// -----------------------------------------------------------------------------

//!< Key [static].
const NsValueWidgetKey 
NsProp4iWidget::key(fromNbStr(Nb::Value4i::staticTypeName()), "");

// -----------------------------------------------------------------------------

// NsProp4iWidget
// --------------
//! CTOR.

NsProp4iWidget::NsProp4iWidget(const NsPropWidgetArgs &args)
    : NsPropBaseWidget(args)
    , _vle0(new NsValueLineEdit(*this, 0))   // Child.
    , _vle1(new NsValueLineEdit(*this, 1))   // Child.
    , _vle2(new NsValueLineEdit(*this, 2))   // Child.
    , _vle3(new NsValueLineEdit(*this, 3))   // Child.
{
    _vle0->setMode(NsValueLineEdit::evaluation);
    _vle1->setMode(NsValueLineEdit::evaluation);
    _vle2->setMode(NsValueLineEdit::evaluation);
    _vle3->setMode(NsValueLineEdit::evaluation);
    _vle0->setReadOnly(true);
    _vle1->setReadOnly(true);
    _vle2->setReadOnly(true);
    _vle3->setReadOnly(true);
    _vle0->onValueChanged();
    _vle1->onValueChanged();
    _vle2->onValueChanged();
    _vle3->onValueChanged();

    valueWidgetLayout()->addWidget(_vle0, 1);
    valueWidgetLayout()->addWidget(_vle1, 1);
    valueWidgetLayout()->addWidget(_vle2, 1);
    valueWidgetLayout()->addWidget(_vle3, 1);
}

// -----------------------------------------------------------------------------

// onModeActionTriggered
// ----------------------
//! Set line edit meta mode. [slot]

void
NsProp4iWidget::onModeActionTriggered(QAction *action)
{
    _vle0->setMode(action->objectName());
    _vle1->setMode(action->objectName());
    _vle2->setMode(action->objectName());
    _vle3->setMode(action->objectName());
    _vle0->setReadOnly(true);
    _vle1->setReadOnly(true);
    _vle2->setReadOnly(true);
    _vle3->setReadOnly(true);
}

// -----------------------------------------------------------------------------

//! Static creator instance.
const NsProp4iWidget::_Creator
    NsProp4iWidget::_creator(*NsPropWidgetFactory::instance());
