/** \file application.h
 *  \brief Application header
 */

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <string>

/** \brief The Application class
 *  You can print your greeting here
 */
class Application {
public:
    /**
     * The constructor
     * @param greeting The greeting statement
     */
    Application(std::string greeting);

    /**
     * The destructor
     */
    virtual ~Application();

    /**
     * Print the greeting statement
     */
    void printHelloWorld();
private:
    std::string greeting; //!< Greeting statement
};

#endif /* define __APPLICATION_H__ */