/*
    Copyright (c) 2017 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "OpenSceneGraphEngineImpl.h"
#include <osg/ShapeDrawable>
#include <osgGA/FlightManipulator>

namespace Kioko
{

OpenSceneGraphEngineImpl::OpenSceneGraphEngineImpl()
{
    m_viewer.setUpViewInWindow(0, 0, 800, 800);

    osg::ref_ptr<osg::ShapeDrawable> shape1 = new osg::ShapeDrawable;
    shape1->setShape(new osg::Box(osg::Vec3(-3.0f, 0.0f, 0.0f),
        2.0f, 2.0f, 1.0f));

    osg::ref_ptr<osg::ShapeDrawable> shape2 = new osg::ShapeDrawable;
    shape2->setShape(new osg::Sphere(osg::Vec3(3.0f, 0.0f, 0.0f),
        1.0f));
    shape2->setColor(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable(shape1.get());
    //root->addDrawable(shape2.get());

    m_viewer.setSceneData(root.get());

    
    //m_viewer.setCameraManipulator(new osgGA::FlightManipulator());

    osg::Vec3d eye(5.0, 5.0, 0.0);
    osg::Vec3d center(1.0, 1.0, 1.0);
    osg::Vec3d up(0.0, 0.0, 1.0);

    m_viewer.getCamera()->setViewMatrixAsLookAt(eye, center, up);

    //m_viewer.run();

    m_viewer.realize();
    while (!m_viewer.done())
    {
        m_viewer.frame();
    }

}

OpenSceneGraphEngineImpl::~OpenSceneGraphEngineImpl()
{
}

}
