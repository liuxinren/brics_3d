/******************************************************************************
* BRICS_3D - 3D Perception and Modeling Library
* Copyright (c) 2011, GPS GmbH
*
* Author: Pinaki Sunil Banerjee
*
*
* This software is published under a dual-license: GNU Lesser General Public
* License LGPL 2.1 and Modified BSD license. The dual-license implies that
* users of this code may choose which terms they prefer.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License LGPL and the BSD license for
* more details.
*
******************************************************************************/

/**
 * @file
 * demoComparison.cpp
 *
 * @author: Pinaki Banerjee
 * @date: Apr 10, 2011
 * @version: 0.1
 *
 * @description
 * This test file demonstrates the use of the Comparison framework to compare he performance of
 * different segmentation algorithm for a particular input scenario. The comparison will be based
 * on the evaluation metrics calculated by the Evaluation Framework provided in BRICS_3D. For more
 * help regarding evaluation metric calculation see "testEvaluation.cpp" in examples.
 */


#include<iostream>
#include <brics_3d/algorithm/segmentation/evaluation/Evaluator.h>
#include <brics_3d/algorithm/segmentation/evaluation/FileReader.h>
#include <brics_3d/algorithm/segmentation/evaluation/FileWriter.h>
#include <brics_3d/algorithm/segmentation/evaluation/MetricCalculator.h>
#include <brics_3d/algorithm/segmentation/evaluation/Comparator.h>
using namespace std;

int main(){

	//NOTE: before using this demo please execute the get_segmentation_data.sh script
	//in the data folder to retrieve the segmentation data sets!

	//Create a string vector containing the names of the methods. These names will be used
	//to fetch the metric files so they should be consistent with the filenames. For more help
	//regarding filename conventions see "trunk/src/brics_3d/algorithm/segmentation/evaluation/FileNameReadMe.txt"
	vector<string> methodNames;
	methodNames.push_back("RANSAC");
	methodNames.push_back("MSAC");
	methodNames.push_back("ALMeDS");

	//create a comparator object
	brics_3d::Comparator comparatorObject;

	//Initialize the coparator object. By default these lines are not required to be changed
	//If the naming conventions are different for storing the evaluation metrics then it
	//should be modified
	comparatorObject.setMethods(methodNames);
	comparatorObject.setPath("../data/segmentation_data/data/");
	comparatorObject.setGtMetricsBaseName("_result_GtMetrics.csv");
	comparatorObject.setMsMetricsBaseName("_result_MsMetrics.csv");
	comparatorObject.setOverlapBaseName("_result_overlapMatrix.csv");

	//Perform the comparison
	comparatorObject.compare();


	cout<<"[Check Point]: Comparison Done :)" << endl;

}

