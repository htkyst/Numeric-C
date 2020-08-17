#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_

static float sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)

static double dsqrarg;
#define DSQR(a) ((dsqrarg=(a)) == 0.0 ? 0.0 : dsqrarg*dsqrarg)

static double dmaxarg1, dmaxarg2;
#define DMAX(a,b) (dmaxarg1=(a), dmaxarg2=(b), \
		(dmaxarg1) > (dmaxarg2) ? (dmaxarg1) : (dmaxarg2))



#endif