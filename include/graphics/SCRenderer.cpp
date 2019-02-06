#include "SCRenderer.hpp"
#include "../utilities/SCUtilities.hpp"

SCRenderer::SCRenderer(sf::RenderWindow * renderWindow)
{
    m_renderWindow = renderWindow;
    m_fps = 60;
    m_framePeriod = 1.0 / m_fps;
    m_startFrameTime = SCUtilities::getCurrentTime();
}

void SCRenderer::render(SCPhysicalArea & pWorld)
{
    /*
    double currentTime = SCUtilities::getCurrentTime();
    if ( (currentTime - m_startFrameTime) >= m_framePeriod )
    {
        m_screen.render(pWorld, currentTime - m_startFrameTime);
        m_startFrameTime = currentTime;
    }
    */
   if (m_renderWindow)
   {
       m_screen.render(m_renderWindow, pWorld);
   }
}