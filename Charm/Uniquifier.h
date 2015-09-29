/*
  Uniquifier.h

  This file is part of Charm, a task-based time tracking application.

  Copyright (C) 2009-2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

  Author: Mirko Boehm <mirko.boehm@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef UNIQUIFIER_H
#define UNIQUIFIER_H

// Usage:
// void blurb() {
//     static bool inProgress = false;
//     if ( inProgress == true ) return;
//     Uniquifier u( &inProgress );
// // ... this code will be called only once
// }

class Uniquifier {
public:
    explicit Uniquifier( bool* guard ) {
        m_guard = guard;
        *m_guard = true;
    }
    ~Uniquifier() {
        *m_guard = false;
    }
private:
    bool *m_guard;
};

#endif