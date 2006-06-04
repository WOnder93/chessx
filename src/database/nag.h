/***************************************************************************
                          nag.h - NAG definitions and NagSet class
                             -------------------
    begin                : 14 April 2006
    copyright            : (C) 2006 William Hoggarth 
													 <whoggarth@users.sourceforge.net>
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef __NAG_H__
#define __NAG_H__

#include <qstring.h>
#include <qglobal.h>
#include <qmap.h>
#include <qt34/qvaluevector.h>

typedef enum {
	NullNag,
	GoodMove,
	PoorMove,
	VeryGoodMove,
	VeryPoorMove,
	SpeculativeMove,
	QuestionableMove,
	ForcedMove,
	SingularMove,
	WorstMove,
	DrawishPosition,
	EqualChancesQuietPosition,
	EqualChancesActivePosition,
	UnclearPosition,
	WhiteHasASlightAdvantage,
	BlackHasASlightAdvantage,
	WhiteHasAModerateAdvantage,
	BlackHasAModerateAdvantage,
	WhiteHasADecisiveAdvantage,
	BlackHasADecisiveAdvantage,
	WhiteHasACrushingAdvantage, 
	BlackHasACrushingAdvantage,
	WhiteIsInZugzwang,
	BlackIsInZugzwang,
	WhiteHasASlightSpaceAdvantage,
	BlackHasASlightSpaceAdvantage,
	WhiteHasAModerateSpaceAdvantage,
	BlackHasAModerateSpaceAdvantage,
	WhiteHasADecisiveSpaceAdvantage,
	BlackHasADecisiveSpaceAdvantage,
	WhiteHasASlightTimeAdvantage,
	BlackHasASlightTimeAdvantage,
	WhiteHasAModerateTimeAdvantage,
	BlackHasAModerateTimeAdvantage,
	WhiteHasADecisiveTimeAdvantage,
	BlackHasADecisiveTimeAdvantage,
	WhiteHasTheInitiative,
	BlackHasTheInitiative,
	WhiteHasALastingInitiative,
	BlackHasALastingInitiative,
	WhiteHasTheAttack,
	BlackHasTheAttack,
	WhiteHasInsufficientCompensationForMaterialDeficit,
	BlackHasInsufficientCompensationForMaterialDeficit,
	WhiteHasSufficientCompensationForMaterialDeficit,
	BlackHasSufficientCompensationForMaterialDeficit,
	WhiteHasMoreThanAdequateCompensationForMaterialDeficit,
	BlackHasMoreThanAdequateCompensationForMaterialDeficit,
	WhiteHasASlightCenterControlAdvantage,
	BlackHasASlightCenterControlAdvantage,
	WhiteHasAModerateCenterControlAdvantage,
	BlackHasAModerateCenterControlAdvantage,
	WhiteHasADecisiveCenterControlAdvantage,
	BlackHasADecisiveCenterControlAdvantage,
	WhiteHasASlightKingsideControlAdvantage,
	BlackHasASlightKingsideControlAdvantage,
	WhiteHasAModerateKingsideControlAdvantage,
	BlackHasAModerateKingsideControlAdvantage,
	WhiteHasADecisiveKingsideControlAdvantage,
	BlackHasADecisiveKingsideControlAdvantage,
	WhiteHasASlightQueensideControlAdvantage,
	BlackHasASlightQueensideControlAdvantage,
	WhiteHasAModerateQueensideControlAdvantage,
	BlackHasAModerateQueensideControlAdvantage,
	WhiteHasADecisiveQueensideControlAdvantage,
	BlackHasADecisiveQueensideControlAdvantage,
	WhiteHasAVulnerableFirstRank,
	BlackHasAVulnerableFirstRank,
	WhiteHasAWellProtectedFirstRank,
	BlackHasAWellProtectedFirstRank,
	WhiteHasAPoorlyProtectedKing,
	BlackHasAPoorlyProtectedKing,
	WhiteHasAWellProtectedKing,
	BlackHasAWellProtectedKing,
	WhiteHasAPoorlyPlacedKing,
	BlackHasAPoorlyPlacedKing,
	WhiteHasAWellPlacedKing,
	BlackHasAWellPlacedKing,
	WhiteHasAVeryWeakPawnStructure,
	BlackHasAVeryWeakPawnStructure,
	WhiteHasAModeratelyWeakPawnStructure,
	BlackHasAModeratelyWeakPawnStructure,
	WhiteHasAModeratelyStrongPawnStructure,
	BlackHasAModeratelyStrongPawnStructure,
	WhiteHasAVeryStrongPawnStructure,
	BlackHasAVeryStrongPawnStructure,
	WhiteHasPoorKnightPlacement,
	BlackHasPoorKnightPlacement,
	WhiteHasGoodKnightPlacement,
	BlackHasGoodKnightPlacement,
	WhiteHasPoorBishopPlacement,
	BlackHasPoorBishopPlacement,
	WhiteHasGoodBishopPlacement,
	BlackHasGoodBishopPlacement,
	WhiteHasPoorRookPlacement,
	BlackHasPoorRookPlacement,
	WhiteHasGoodRookPlacement,
	BlackHasGoodRookPlacement,
	WhiteHasPoorQueenPlacement,
	BlackHasPoorQueenPlacement,
	WhiteHasGoodQueenPlacement,
	BlackHasGoodQueenPlacement,
	WhiteHasPoorPieceCoordination,
	BlackHasPoorPieceCoordination,
	WhiteHasGoodPieceCoordination,
	BlackHasGoodPieceCoordination,
	WhiteHasPlayedTheOpeningVeryPoorly,
	BlackHasPlayedTheOpeningVeryPoorly,
	WhiteHasPlayedTheOpeningPoorly,
	BlackHasPlayedTheOpeningPoorly,
	WhiteHasPlayedTheOpeningWell,
	BlackHasPlayedTheOpeningWell,
	WhiteHasPlayedTheOpeningVeryWell,
	BlackHasPlayedTheOpeningVeryWell,
	WhiteHasPlayedTheMiddlegameVeryPoorly,
	BlackHasPlayedTheMiddlegameVeryPoorly,
	WhiteHasPlayedTheMiddlegamePoorly,
	BlackHasPlayedTheMiddlegamePoorly,
	WhiteHasPlayedTheMiddlegameWell,
	BlackHasPlayedTheMiddlegameWell,
	WhiteHasPlayedTheMiddlegameVeryWell,
	BlackHasPlayedTheMiddlegameVeryWell,
	WhiteHasPlayedTheEndingVeryPoorly,
	BlackHasPlayedTheEndingVeryPoorly,
	WhiteHasPlayedTheEndingPoorly,
	BlackHasPlayedTheEndingPoorly,
	WhiteHasPlayedTheEndingWell,
	BlackHasPlayedTheEndingWell,
	WhiteHasPlayedTheEndingVeryWell,
	BlackHasPlayedTheEndingVeryWell,
	WhiteHasSlightCounterplay,
	BlackHasSlightCounterplay,
	WhiteHasModerateCounterplay,
	BlackHasModerateCounterplay,
	WhiteHasDecisiveCounterplay,
	BlackHasDecisiveCounterplay,
	WhiteHasModerateTimeControlPressure,
	BlackHasModerateTimeControlPressure,
	WhiteHasSevereTimeControlPressure,
	BlackHasSevereTimeControlPressure,
	NagCount
} Nag;

const QString NagStrings[NagCount] = {
	"",
	"!",
	"?",
	"!!",
	"??",
	"!?",
	"?!",
	"forced move",
	"singular move",
	"worst move",
	"drawish position",
	"equal chances, quiet position",
	"equal chances, active position",
	"unclear position",
	"+=",
	"=+",
	"+/-",
	"-/+",
	"White has a decisive advantage",
	"Black has a decisive advantage",
	"White has a crushing advantage",
	"Black has a crushing advantage",
	"White is in zugzwang",
	"Black is in zugzwang",
	"White has a slight space advantage",
	"Black has a slight space advantage",
	"White has a moderate space advantage",
	"Black has a moderate space advantage",
	"White has a decisive space advantage",
	"Black has a decisive space advantage",
	"White has a slight time (development) advantage",
	"Black has a slight time (development) advantage",
	"White has a moderate time (development) advantage",
	"Black has a moderate time (development) advantage",
	"White has a decisive time (development) advantage",
	"Black has a decisive time (development) advantage",
	"White has the initiative",
	"Black has the initiative",
	"White has a lasting initiative",
	"Black has a lasting initiative",
	"White has the attack",
	"Black has the attack",
	"White has insufficient compensation for material deficit",
	"Black has insufficient compensation for material deficit",
	"White has sufficient compensation for material deficit",
	"Black has sufficient compensation for material deficit",
	"White has more than adequate compensation for material deficit",
	"Black has more than adequate compensation for material deficit",
	"White has a slight center control advantage",
	"Black has a slight center control advantage",
	"White has a moderate center control advantage",
	"Black has a moderate center control advantage",
	"White has a decisive center control advantage",
	"Black has a decisive center control advantage",
	"White has a slight kingside control advantage",
	"Black has a slight kingside control advantage",
	"White has a moderate kingside control advantage",
	"Black has a moderate kingside control advantage",
	"White has a decisive kingside control advantage",
	"Black has a decisive kingside control advantage",
	"White has a slight queenside control advantage",
	"Black has a slight queenside control advantage",
	"White has a moderate queenside control advantage",
	"Black has a moderate queenside control advantage",
	"White has a decisive queenside control advantage",
	"Black has a decisive queenside control advantage",
	"White has a vulnerable first rank",
	"Black has a vulnerable first rank",
	"White has a well protected first rank",
	"Black has a well protected first rank",
	"White has a poorly protected king",
	"Black has a poorly protected king",
	"White has a well protected king",
	"Black has a well protected king",
	"White has a poorly placed king",
	"Black has a poorly placed king",
	"White has a well placed king",
	"Black has a well placed king",
	"White has a very weak pawn structure",
	"Black has a very weak pawn structure",
	"White has a moderately weak pawn structure",
	"Black has a moderately weak pawn structure",
	"White has a moderately strong pawn structure",
	"Black has a moderately strong pawn structure",
	"White has a very strong pawn structure",
	"Black has a very strong pawn structure",
	"White has poor knight placement",
	"Black has poor knight placement",
	"White has good knight placement",
	"Black has good knight placement",
	"White has poor bishop placement",
	"Black has poor bishop placement",
	"White has good bishop placement",
	"Black has good bishop placement",
	"White has poor rook placement",
	"Black has poor rook placement",
	"White has good rook placement",
	"Black has good rook placement",
	"White has poor queen placement",
	"Black has poor queen placement",
	"White has good queen placement",
	"Black has good queen placement",
	"White has poor piece coordination",
	"Black has poor piece coordination",
	"White has good piece coordination",
	"Black has good piece coordination",
	"White has played the opening very poorly",
	"Black has played the opening very poorly",
	"White has played the opening poorly",
	"Black has played the opening poorly",
	"White has played the opening well",
	"Black has played the opening well",
	"White has played the opening very well",
	"Black has played the opening very well",
	"White has played the middlegame very poorly",
	"Black has played the middlegame very poorly",
	"White has played the middlegame poorly",
	"Black has played the middlegame poorly",
	"White has played the middlegame well",
	"Black has played the middlegame well",
	"White has played the middlegame very well",
	"Black has played the middlegame very well",
	"White has played the ending very poorly",
	"Black has played the ending very poorly",
	"White has played the ending poorly",
	"Black has played the ending poorly",
	"White has played the ending well",
	"Black has played the ending well",
	"White has played the ending very well",
	"Black has played the ending very well",
	"White has slight counterplay",
	"Black has slight counterplay",
	"White has moderate counterplay",
	"Black has moderate counterplay",
	"White has decisive counterplay",
	"Black has decisive counterplay",
	"White has moderate time control pressure",
	"Black has moderate time control pressure",
	"White has severe time control pressure",
	"Black has severe time control pressure"
};

class NagSet 
{
	public:
		NagSet();
		NagSet(Nag nag);
		NagSet(const QValueVector<Nag>& nags);
		
		void addNag(Nag nag);
		void removeNag(Nag nag);
		void clear();
		int count();
		
		QValueVector<Nag> nags() const;
		QString toString() const;
		QString toPGNString() const;
		
		static QString nagToString(Nag nag);
		static Nag stringToNag(const QString& nagString);
		
	private:
		static void initialize();
	
		static const unsigned int MaxNags = 8;
		Q_UINT8 m_noNags;
		Q_INT8 m_nags[MaxNags];
		
		static bool initialized;
		static QMap<QString,Nag> stringMap;
};

#endif	// __NAG_H__

