// -----------------------------------------------------------------------------
//
// NsTimeLineEdit.cc
//
// Naiad Studio time line edit, source file.
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

#include "NsTimeLineEdit.h"
#include "NsIntValidator.h"

// -----------------------------------------------------------------------------

// NsTimeLineEdit
// --------------
//! CTOR.

NsTimeLineEdit::NsTimeLineEdit(QWidget *parent)
    : NsLineEdit("0", parent)
{
    NsIntValidator *iv(new NsIntValidator(this));   // Child.
    setValidator(iv);

    connect(this, 
            SIGNAL(editingFinished()),
            SLOT(onEditingFinished()));
}

// -----------------------------------------------------------------------------

// onValueChanged
// --------------
//! [slot]

void
NsTimeLineEdit::onValueChanged(const int value)
{
    _setValue(value);
}

// -----------------------------------------------------------------------------

// onEditingFinished
// -----------------
//! [slot]

void
NsTimeLineEdit::onEditingFinished()
{
    int i(0);
    if (_value(&i)) {
        emit valueChanged(i);
    }
}

// -----------------------------------------------------------------------------

// _setValue
// ---------
//! DOCS

void
NsTimeLineEdit::_setValue(const int value)
{
    int i(0);
    if (_value(&i) && i != value) {
        NsLineEdit::setText(QString::number(value));
    }
}


// _value
// ------
//! DOCS

bool
NsTimeLineEdit::_value(int *val)
{
    bool ok(false);
    const int i(text().toInt(&ok)); // Should be OK thanks to validator...

    if (0 != val) {
        *val = i;
    }

    return ok;
}
