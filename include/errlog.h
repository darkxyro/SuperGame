#ifndef ERRLOG_H_INCLUDED
#define ERRLOG_H_INCLUDED

/**
* log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
inline void logSDLError(std::ostream &os, const std::string &msg){
	os<<msg<<" Error: "<<SDL_GetError()<<std::endl;
}

#endif // ERRLOG_H_INCLUDED
