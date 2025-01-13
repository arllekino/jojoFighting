#pragma once

enum ActionType
{
	onStay,
	onGoing,
	onTurn,
	onCrouch,
	onStandingFromCrouch,
	onTurnWhileCrouch,
	onDashForward,
	onDashBack,
	onJump,
	onSummon,
	onSummonMidAir,
	onUnsummon,
	onStandAttack,
	onCrouchAttackForward,
	onCrouchPowerfulAttackForward,
	onArmMediumAttack, // standing/dashing
	onLegMediumAttack, // standing
	onLegMediumAttackMidAir, 
	onStandCrouchingAttack, // crouching
	onStandAttackUp, // standing/dashing
	onStandAttackDown, // forward + heavyAttack
	onStandAttackCrouchingDown, // heavy attack + crouching
	onStandAttackCrouchingUp, // heavy attack down forward
	onOraOra, // obviously
	onHitedHeadStraight,
	onHitedHeadDownUp,
	onHitedHeadUpDown, 
	onHitedTorsoStraight,
	onHitedTorsoDownUp,
	onHitedLegStraight,
	onHitedLegWithFall,
	onHitedTorsoWithFall,
	onHitedInSit,
	onHitedInJump,
	onUlt,
	onCallSupport,
	onHaha,
	onTakeHit,
	atDeath,
	onWin,
	onWinCycle,
	avatar
};