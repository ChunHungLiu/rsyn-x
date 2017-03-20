/* Copyright 2014-2017 Rsyn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef BALANCING_OPTO_H
#define BALANCING_OPTO_H

#include "rsyn/engine/Engine.h"
#include "rsyn/phy/PhysicalService.h"
#include "x/infra/iccad15/utilICCAD15.h"
namespace Rsyn {
class LibraryCharacterizer;
class Timer;
class RoutingEstimator;
}

namespace ICCAD15 {

class Infrastructure;

class Balancing : public Rsyn::Process {
private:
	Rsyn::Engine engine;
	Infrastructure * infra;
	Rsyn::Design design;
	Rsyn::Module module;
	Rsyn::PhysicalDesign phDesign;
	Rsyn::Timer *timer;
	Rsyn::PhysicalService * physical;
	Rsyn::RoutingEstimator * routingEstimator;
	const Rsyn::LibraryCharacterizer * libc;
	
	bool doBufferBalancing(Rsyn::Cell buffer, 
						   const LegalizationMethod legalizationMethod, 
						   const CostFunction costFunction);
	
	bool doCellBalancing(Rsyn::Cell cell, 
						 const LegalizationMethod legalizationMethod, 
						 const CostFunction costFunction);
	
	bool doCellBalancingSteiner(Rsyn::Cell cell, 
								const LegalizationMethod legalizationMethod,
								const CostFunction costFunction);	
	
	void runBufferFix(); 
	void runCellFix();
	void runCellFixSteiner();	
	
public:
	
	virtual bool run(Rsyn::Engine engine, const Rsyn::Json &params);
	
}; // end class

}
#endif