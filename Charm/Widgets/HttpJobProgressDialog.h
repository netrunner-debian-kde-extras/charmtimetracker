/*
  HttpJobProgressDialog.h

  This file is part of Charm, a task-based time tracking application.

  Copyright (C) 2014-2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

  Author: Frank Osterfeld <frank.osterfeld@kdab.com>

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

#ifndef HTTPJOBPROGRESSDIALOG_H
#define HTTPJOBPROGRESSDIALOG_H

#include <QProgressDialog>
#include <QPointer>
#include "HttpClient/HttpJob.h"

class HttpJobProgressDialog : public QProgressDialog
{
    Q_OBJECT
public:
    explicit HttpJobProgressDialog( HttpJob* job, QWidget* parent = nullptr );

private Q_SLOTS:
    void jobFinished( HttpJob* );
    void jobTransferStarted();
    void jobPasswordRequested();

private:
    QPointer<HttpJob> m_job;
};

#endif
