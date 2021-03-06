/*
  CommandSetAllTasks.h

  This file is part of Charm, a task-based time tracking application.

  Copyright (C) 2008-2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

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

#ifndef COMMANDSETALLTASKS_H
#define COMMANDSETALLTASKS_H

#include <Core/Task.h>
#include <Core/CharmCommand.h>

class CommandSetAllTasks : public CharmCommand
{
    Q_OBJECT

public:
    explicit CommandSetAllTasks( const TaskList&, QObject* parent );
    ~CommandSetAllTasks();

    bool prepare() override;
    bool execute( ControllerInterface* ) override;
    bool finalize() override;

private:
    TaskList m_tasks;
    bool m_success;
};

#endif
