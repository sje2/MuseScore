//=============================================================================
//  MusE Score
//  Linux Music Score Editor
//  $Id:$
//
//  Copyright (C) 2009 Werner Schweer and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================

#include "piano.h"

QPixmap* Piano::octave;
QPixmap* Piano::mk1;
QPixmap* Piano::mk2;
QPixmap* Piano::mk3;
QPixmap* Piano::mk4;

//---------------------------------------------------------
//   Piano
//---------------------------------------------------------

Piano::Piano(QWidget* parent)
   : QWidget(parent)
      {
      setMouseTracking(true);
      _ymag = 1.0;
      setAttribute(Qt::WA_NoSystemBackground);
      setAttribute(Qt::WA_StaticContents);
      setMouseTracking(true);

      /*
            0   1   2  3  4  5  6  7  8  9  10
            c-2 c-1 C0 C1 C2 C3 C4 C5 C6 C7 C8 - G8

            Grid ve:

                 +------------+ ------------------------------
             11  |            |
                 |         b  |         7
                 +------+     |
             10  |  a#  +-----+ ..............................
                 +------+  a  |
              9  |            |         6
                 +------+     |
              8  |  g#  +-----+ ..............................
                 +------+  g  |
              7  |            |         5
                 +------+     |
              6  |  f#  +-----+ ..............................
                 +------+  f  |
              5  |            |         4
                 |            |
                 +------------+ ------------------------------
              4  |            |
                 |         e  |         3
                 +------+     |
              3  |  d#  +-----+ ..............................
                 +------+  d  |
              2  |            |         2
                 +------+     |
              1  |  c#  +-----+ ..............................
                 +------+  c  |
                 |            |         1
              0  |            |
                 +------------+ ------------------------------
       */

      static const char *oct_xpm[] = {
            // w h colors
                  "40 91 2 1",
                  ". c #f0f0f0",
                  "# c #000000",
                  //           x
                  "####################################### ",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", // 10
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", //------------------------
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",
                  "####################################### ",     // 7
                  "########################...............#",
                  "########################...............#",
                  "#######################................#", //------------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",     // 6
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", //------------------------
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",     // 7
                  "####################################### ",
                  "########################...............#",
                  "########################...............#",
                  "#######################................#", //------------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",    // 6
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", //------------------------
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",    // 7
                  "####################################### ",
                  "########################...............#",
                  "########################...............#",
                  "#######################................#", //------------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",    // 10
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  "####################################### ", //----------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",    // 9
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", //------------------------
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",
                  "####################################### ",   // 7
                  "########################...............#",
                  "########################...............#",
                  "#######################................#", //------------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",     // 6
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", //--------------------------
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",     // 7
                  "####################################### ",
                  "########################...............#",
                  "########################...............#",
                  "#######################................#", //------------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",     // 10
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  };

      static const char *mk1_xpm[] = {
                  "40 13 2 1",
                  ". c #ff0000",
                  "# c none",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",
                  "####################################### ",
                  };

      static const char *mk2_xpm[] = {
                  "40 13 2 1",
                  ". c #ff0000",
                  "# c none",
                  "########################...............#",
                  "########################...............#",
                  "#######################................#", //------------------------
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",     // 6
                  ".......................................#",
                  ".......................................#",
                  ".......................................#", //--------------------------
                  "#######################................#",
                  "########################...............#",
                  "########################...............#",     // 7
                  "####################################### ",
                  };

      static const char *mk3_xpm[] = {
                  "40 13 2 1",
                  ". c #ff0000",
                  "# c none",
                  "########################...............#",
                  "########################...............#",
                  "#######################................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  ".......................................#",
                  "########################################",
                  };

      static const char *mk4_xpm[] = {
                  "40 13 2 1",
                  "# c #ff0000",
                  ". c none",
                  "........................................",
                  "........................................",
                  "........................................",
                  "#######################.................",
                  "########################................",
                  "########################................",
                  "########################................",
                  "########################................",
                  "########################................",
                  "#######################.................",
                  "........................................",
                  "........................................",
                  "........................................",
                  };

      if (octave == 0) {
            octave = new QPixmap(oct_xpm);
            mk1    = new QPixmap(mk1_xpm);
            mk2    = new QPixmap(mk2_xpm);
            mk3    = new QPixmap(mk3_xpm);
            mk4    = new QPixmap(mk4_xpm);
            }
      yRange   = keyHeight * 75;
      curPitch = -1;
      _ypos    = 0;
      curKeyPressed = -1;
      _orientation = PIANO_VERTICAL;
      }

//---------------------------------------------------------
//   pitch2y
//    y = 0 == origin of rCanvasA
//---------------------------------------------------------

int Piano::pitch2y(int pitch) const
      {
      static int tt[] = {
         12, 19, 25, 32, 38, 51, 58, 64, 71, 77, 84, 90
         };
      int y = (75 * keyHeight) - (tt[pitch % 12] + (7 * keyHeight) * (pitch / 12));
      if (y < 0)
            y = 0;
      return lrint(y - _ypos / _ymag);
      }

//---------------------------------------------------------
//   y2pitch
//    y = 0 == origin of rCanvasA
//---------------------------------------------------------

int Piano::y2pitch(int y) const
      {
      y = lrint((y + _ypos) / _ymag);
      static const int total = (10 * 7 + 5) * keyHeight;     // 75 steps
      y = total - y;
      int oct = (y / (7 * keyHeight)) * 12;
      static const char kt[] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2, 2, 2,
            3, 3, 3, 3, 3, 3, 3,
            4, 4, 4, 4, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
            6, 6, 6, 6, 6, 6, 6,
            7, 7, 7, 7, 7, 7,
            8, 8, 8, 8, 8, 8, 8,
            9, 9, 9, 9, 9, 9,
            10, 10, 10, 10, 10, 10, 10,
            11, 11, 11, 11, 11, 11, 11, 11, 11, 11
            };
      int pitch = kt[y % 91] + oct;
      if (pitch < 0 || pitch > 127)
            pitch = -1;
      return pitch;
      }

//---------------------------------------------------------
//   paint
//---------------------------------------------------------

void Piano::paintEvent(QPaintEvent* event)
      {
      QPainter p(this);
      const QRect& rr = event->rect();
      QRect r;
      if (_orientation == PIANO_HORIZONTAL) {
            int w = keyHeight * 52;
            p.translate(w, 0);
            p.rotate(90.0);
            r.setWidth(rr.height());
            r.setHeight(rr.width());
            r.setX(0);
            r.setY(0);
            }
      else
            r = rr;
      p.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
      int   d = int(_ymag)+1;
      qreal x = qreal(r.x());
      qreal y = 0.0;
      qreal h = (r.height()+d) / _ymag;
      QPointF offset(x, _ypos / _ymag + keyHeight * 2 + y);

      p.scale(1.0, _ymag);
      p.drawTiledPixmap(QRectF(x, y, qreal(r.width()), h), *octave, offset);

      if (curPitch != -1) {
            int y = pitch2y(curPitch);
            QPixmap* pm;
            switch(curPitch % 12) {
                  case 0:
                  case 5:
                        pm = mk3;
                        break;
                  case 2:
                  case 7:
                  case 9:
                        pm = mk2;
                        break;
                  case 4:
                  case 11:
                        pm = mk1;
                        break;
                  default:
                        pm = mk4;
                        break;
                  }
            p.drawPixmap(0, y, *pm);
            }
      }

//---------------------------------------------------------
//   setYpos
//---------------------------------------------------------

void Piano::setYpos(int val)
      {
      if (_ypos != val) {
            _ypos = val;
            update();
            }
      }

//---------------------------------------------------------
//   setMag
//---------------------------------------------------------

void Piano::setMag(double, double ym)
      {
      if (_ymag != ym) {
            _ymag = ym;
            update();
            }
      }

//---------------------------------------------------------
//   setPitch
//---------------------------------------------------------

void Piano::setPitch(int val)
      {
      if (curPitch != val) {
            curPitch = val;
            update();
            }
      }

//---------------------------------------------------------
//   mousePressEvent
//---------------------------------------------------------

void Piano::mousePressEvent(QMouseEvent* event)
      {
      curKeyPressed = y2pitch(event->pos().y());
      emit keyPressed(curKeyPressed);
      }

//---------------------------------------------------------
//   mouseReleaseEvent
//---------------------------------------------------------

void Piano::mouseReleaseEvent(QMouseEvent*)
      {
      emit keyReleased(curKeyPressed);
      curKeyPressed = -1;
      }

//---------------------------------------------------------
//   mouseMoveEvent
//---------------------------------------------------------

void Piano::mouseMoveEvent(QMouseEvent* event)
      {
      int pitch = y2pitch(event->pos().y());
      if (pitch != curPitch) {
            curPitch = pitch;
            emit pitchChanged(curPitch);
            if ((curKeyPressed != -1) && (curKeyPressed != pitch)) {
                  emit keyReleased(curKeyPressed);
                  curKeyPressed = pitch;
                  emit keyPressed(curKeyPressed);
                  }
            update();
            }
      }

//---------------------------------------------------------
//   leaveEvent
//---------------------------------------------------------

void Piano::leaveEvent(QEvent*)
      {
      if (curPitch != -1) {
            curPitch = -1;
            emit pitchChanged(-1);
            update();
            }
      }

//---------------------------------------------------------
//   setOrientation
//---------------------------------------------------------

void Piano::setOrientation(PianoOrientation o)
      {
      _orientation = o;
      update();
      }
